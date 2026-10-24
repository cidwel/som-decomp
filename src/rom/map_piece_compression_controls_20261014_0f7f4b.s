.setcpu "65816"
.segment "CODE"
.org $7F4B
map_control_0f7f4b:
    .byte $E7 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
