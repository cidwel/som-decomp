.setcpu "65816"
.segment "CODE"
.org $E262
map_control_0de262:
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E3 ; previous-row copy count
