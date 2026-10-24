; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-personality-page.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6C92
select_native_current_hero_weapon_skill_index:
    lda f:$0019FE
    rep #$20
    xba
    .a16
    and #$FF00
    asl
    tax
    sep #$20
    lda a:$E1E4,X
    sta a:$A175
    rts
