; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-motion.md.
.setcpu "65816"
.smart
.a8
.i16

append_or_retire_native_visual_effect_trail_points = $ACAC

.segment "CODE"
.org $ACA8
publish_native_visual_effect_point_trail_long:
    jsr append_or_retire_native_visual_effect_trail_points
    rtl
