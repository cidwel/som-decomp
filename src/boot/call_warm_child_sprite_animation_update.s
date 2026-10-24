; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-child-animation.md.
.setcpu "65816"
.smart
.a8
.i16

update_nine_warm_child_sprite_animation_records = $BA21

.segment "CODE"
.org $BA0C
call_warm_child_sprite_animation_update:
    ldx $01
    jsr update_nine_warm_child_sprite_animation_records
