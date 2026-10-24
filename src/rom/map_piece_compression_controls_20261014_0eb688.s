.setcpu "65816"
.segment "CODE"
.org $B688
map_control_0eb688:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
