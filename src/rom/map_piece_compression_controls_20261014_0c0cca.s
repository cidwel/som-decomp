.setcpu "65816"
.segment "CODE"
.org $0CCA
map_control_0c0cca:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
