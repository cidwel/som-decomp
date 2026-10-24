; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-constructor.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_twelve_party_scene_animation_frames = $FB0D

.segment "CODE"
.org $FB01
load_party_scene_frames_with_saved_data_bank:
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    jsr initialize_twelve_party_scene_animation_frames
    plb
    rts
