#pragma once

#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/rgb.h>

/* Layer definition */
#define DEF 0
#define BAS 0
#define NUM 1
#define NAV 2
#define SYM 3
#define FUN 4

/* Timing */
#define TAPPING_TERM 200
#define QUICK_TAP_MS 0

/ {
    combos {
        compatible = "zmk,combos";

        #define COMBO(NAME, BINDINGS, KEYPOS, TIMEOUT, LAYERS) \
            combo_##NAME { \
                timeout-ms = <TIMEOUT>; \
                bindings = <BINDINGS>; \
                key-positions = <KEYPOS>; \
                layers = <LAYERS>; \
                slow-release; \
            };

        #define DEFAULT_TIME 64
        #define LONG_TIME    128

        #define ALL_LAYERS     BAS NUM FUN SYM NAV
        #define DEFAULT_LAYERS BAS NUM FUN SYM NAV
        #define NONBASE_LAYERS     NUM FUN SYM NAV

        COMBO(z,     &kp Y,       4   5, DEFAULT_TIME, BAS)
        COMBO(q,     &kp Q,       0   1, DEFAULT_TIME, BAS)
        COMBO(tab,   &kp TAB,     8   9, DEFAULT_TIME, BAS)
        COMBO(esc,   &kp ESC,     18   19, DEFAULT_TIME, BAS)
        COMBO(enter, &kp ENTER,  24  26, DEFAULT_TIME, BAS)
        COMBO(QMARK, &kp QMARK, 25 26, DEFAULT_TIME, BAS)
    };

    macros {
        ipad_tile_left: ipad_tile_left {
            label = "ipad_tile_left";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings
                = <&macro_press &kp LCTRL>
                , <&macro_press &kp LGUI>
                , <&macro_tap &kp LEFT>
                , <&macro_release &kp LGUI>
                , <&macro_release &kp LCTRL>
                ;
        };

        ipad_tile_right: ipad_tile_right {
            label = "ipad_tile_right";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings
                = <&macro_press &kp LCTRL>
                , <&macro_press &kp LGUI>
                , <&macro_tap &kp RIGHT>
                , <&macro_release &kp LGUI>
                , <&macro_release &kp LCTRL>
                ;
        };

        ipad_tile_fullscreen: ipad_tile_fullscreen {
            label = "ipad_tile_fullscreen";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings
                = <&macro_press &kp LGUI>
                , <&macro_tap &kp F>
                , <&macro_release &kp LGUI>
                ;
        };
    };

    behaviors {
        hl: homerow_left {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow left mods";
            #binding-cells = <2>;
            tapping-term-ms = <TAPPING_TERM>;
            quick-tap-ms = <QUICK_TAP_MS>;
            flavor = "balanced";
            bindings = <&kp>, <&kp>;
            hold-trigger-key-positions = <5 6 7 8 9 15 16 17 18 19 25 26 27 28 29>;
            hold-trigger-on-release;
        };

        hr: homerow_right {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow right mods";
            #binding-cells = <2>;
            tapping-term-ms = <TAPPING_TERM>;
            quick-tap-ms = <QUICK_TAP_MS>;
            flavor = "balanced";
            bindings = <&kp>, <&kp>;
            hold-trigger-key-positions = <0 1 2 3 4 10 11 12 13 14 20 21 22 23 24>;
            hold-trigger-on-release;
        };

        my_lt: my_layer_tap {
            compatible = "zmk,behavior-hold-tap";
            label = "my layer tap";
            #binding-cells = <2>;
            tapping-term-ms = <200>;
            quick-tap-ms = <0>;
            flavor = "balanced";
            bindings = <&mo>, <&kp>;
        };

        dotcol: dot_colon {
            compatible = "zmk,behavior-mod-morph";
            label = "DOT/COLON";
            #binding-cells = <0>;
            bindings = <&kp DOT>, <&kp COLON>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };

        comsem: comma_semicolon {
            compatible = "zmk,behavior-mod-morph";
            label = "COMMA/SEMICOLON";
            #binding-cells = <0>;
            bindings = <&kp COMMA>, <&kp SEMICOLON>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
    };
};
