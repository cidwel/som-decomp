; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-sprites.md.
.setcpu "65816"
.smart
.a8
.i16

emit_packed_actor_sprite_list = $E640

.segment "CODE"
.org $9EF5
forward_ui_party_icon_to_native_packed_sprite_emitter:
    stx $04
    sty $06
    tax
    .a16
    lda #$0004
    sta $02
    jmp emit_packed_actor_sprite_list
