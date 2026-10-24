.setcpu "65816"
.segment "CODE"
.org $9AAD
map_control_0e9aad:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $AD ; row-distance/count
