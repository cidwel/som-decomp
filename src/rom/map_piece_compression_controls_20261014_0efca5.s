.setcpu "65816"
.segment "CODE"
.org $FCA5
map_control_0efca5:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E7 ; previous-row copy count
