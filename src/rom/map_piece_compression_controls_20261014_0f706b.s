.setcpu "65816"
.segment "CODE"
.org $706B
map_control_0f706b:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E3 ; previous-row copy count
