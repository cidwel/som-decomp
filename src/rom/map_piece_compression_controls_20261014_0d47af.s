.setcpu "65816"
.segment "CODE"
.org $47AF
map_control_0d47af:
    .byte $F0 ; progressive-copy escape
    .byte $82 ; direction/count
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
