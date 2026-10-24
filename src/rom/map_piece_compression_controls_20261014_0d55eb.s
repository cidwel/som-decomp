.setcpu "65816"
.segment "CODE"
.org $55EB
map_control_0d55eb:
    .byte $E7 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
