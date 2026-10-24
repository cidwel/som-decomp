.setcpu "65816"
.segment "CODE"
.org $8194
map_control_0f8194:
    .byte $CD ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E6 ; previous-row copy count
