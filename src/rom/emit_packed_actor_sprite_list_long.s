; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

emit_packed_actor_sprite_list = $E640

.segment "CODE"
.org $E324
emit_packed_actor_sprite_list_long:
    jsr emit_packed_actor_sprite_list
    rtl
