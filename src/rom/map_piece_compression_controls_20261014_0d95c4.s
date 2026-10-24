.setcpu "65816"
.segment "CODE"
.org $95C4
map_control_0d95c4:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E6 ; previous-row copy count
