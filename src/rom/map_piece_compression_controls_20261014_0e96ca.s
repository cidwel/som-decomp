.setcpu "65816"
.segment "CODE"
.org $96CA
map_control_0e96ca:
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
