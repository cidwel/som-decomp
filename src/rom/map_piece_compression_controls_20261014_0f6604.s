.setcpu "65816"
.segment "CODE"
.org $6604
map_control_0f6604:
    .byte $E6 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
