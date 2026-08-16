// vim: set ft=dts:
#include <behaviors.dtsi>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/outputs.h>

#define DEF 0
#define NUM 1
#define NAV 2
#define SYM 3
#define FUN 4

// &lt {
//     quick_tap_ms = <170>;
// };

&caps_word {
    continue-list = <UNDERSCORE MINUS BSPC LSHFT RSHFT>;
};

/ {
  macros {
    ipad_tile_left: ipad_tile_left {
      label = "iPad Tile Left";
      compatible = "zmk,behavior-macro";
      #binding-cells = <0>;
      bindings = <
        &macro_press   &kp LCTRL
        &macro_press   &kp GLOBE      
        &macro_tap     &kp LEFT
        &macro_release &kp GLOBE
        &macro_release &kp LCTRL
      >;
    };
  };
};
/ {
  macros {
    ipad_tile_right: ipad_tile_right {
      label = "iPad Tile Right";
      compatible = "zmk,behavior-macro";
      #binding-cells = <0>;
      bindings = <
        &macro_press   &kp LCTRL
        &macro_press   &kp GLOBE      
        &macro_tap     &kp RIGHT
        &macro_release &kp GLOBE
        &macro_release &kp LCTRL
      >;
    };
  };
};
/ {
  macros {
    ipad_tile_fullscreen: ipad_tile_fullscreen {
      label = "iPad Tile fullscreen";
      compatible = "zmk,behavior-macro";
      #binding-cells = <0>;
      bindings = <
        &macro_press   &kp GLOBE      
        &macro_tap     &kp F
        &macro_release &kp GLOBE
      >;
    };
  };
};


#define COMBO(NAME, BINDINGS, KEYPOS) \
combo_##NAME { \
    timeout-ms = <20>; \
    bindings = <BINDINGS>; \
    key-positions = <KEYPOS>; \
};

/ {
    combos {
        compatible = "zmk,combos";
/* base layer */
        COMBO(z, &kp Y, 4 5)
        COMBO(v, &kp Q, 0 1)
        COMBO(question, &kp QMARK, 25 26)
        COMBO(enter, &kp ENTER, 24 26)
        COMBO(esc, &kp ESC, 18 19)
/* parentheticals */
        
/* alternative shifting */

    };
};

//     __________________________  __________________________
//    /     0  |  1  |  2  |  3  \/   4 |   5 |   6 |   7    \
// |  8  |  9  | 10  | 11  | 12  /\  13 |  14 |  15 |  16 | 17  |
//    \    18  | 19  | 20    /        \    21 |  22 |  23   /
//          \    24  | 25  /            \  26 |  27    /
//           --------------              --------------


/ {

    behaviors {
        hl: homerow_mods_left {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods left";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <250>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <4 5 6 7 13 14 15 16 17 21 22 23 24 25 26 27>;
        };
        hr: homerow_mods_right {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods right";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <250>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <0 1 2 3 8 9 10 11 12 18 19 20 24 25 26 27>;
        };

        my_lt: my_layer_taps {
            compatible = "zmk,behavior-hold-tap";
            label = "my layer taps";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <250>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&mo &kp>, <&kp>;
            // non-thumb keys
            // hold-trigger-key-positions = <0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23>;
        };

        dotcol: dot_colon {
            compatible = "zmk,behavior-mod-morph";
            label = "DOT_COL";
            #binding-cells = <0>;
            bindings = <&kp DOT>, <&kp COLON>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
        comsem: comma_semicolon {
            compatible = "zmk,behavior-mod-morph";
            label = "COM_SEM";
            #binding-cells = <0>;
            bindings = <&kp COMMA>, <&kp SEMI>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
    };
};
