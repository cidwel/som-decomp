.setcpu "65816"
.segment "CODE"
.org $9CE2
map_control_0e9ce2:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
