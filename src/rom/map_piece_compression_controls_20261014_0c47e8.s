.setcpu "65816"
.segment "CODE"
.org $47E8
map_control_0c47e8:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E1 ; previous-row copy count
