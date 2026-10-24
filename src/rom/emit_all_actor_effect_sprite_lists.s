; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

emit_packed_actor_sprite_list = $E640
finish_actor_sprite_emission = $E8C6
prepare_merged_actor_effect_sprites = $19017
prepare_one_actor_effect_sprite_list = $19106

.segment "CODE"
.org $E88A
emit_all_actor_effect_sprite_lists:
    rep #$20
    .a16
    lda #$0000
    ora $14
    tay
    jsl f:prepare_one_actor_effect_sprite_list
    bcc emit_all_actor_effect_sprite_lists_c0e89b
    jsr emit_packed_actor_sprite_list
emit_all_actor_effect_sprite_lists_c0e89b:
    rep #$20
    .a16
    lda #$0010
    ora $14
    tay
    jsl f:prepare_one_actor_effect_sprite_list
    bcc emit_all_actor_effect_sprite_lists_c0e8ac
    jsr emit_packed_actor_sprite_list
emit_all_actor_effect_sprite_lists_c0e8ac:
    rep #$20
    .a16
    lda #$0020
    ora $14
    tay
    jsl f:prepare_one_actor_effect_sprite_list
    bcc emit_all_actor_effect_sprite_lists_c0e8bd
    jsr emit_packed_actor_sprite_list
emit_all_actor_effect_sprite_lists_c0e8bd:
    jsl f:prepare_merged_actor_effect_sprites
    bcc finish_actor_sprite_emission
    jsr emit_packed_actor_sprite_list
