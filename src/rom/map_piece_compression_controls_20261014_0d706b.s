.setcpu "65816"
.segment "CODE"
.org $706B
map_control_0d706b:
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
