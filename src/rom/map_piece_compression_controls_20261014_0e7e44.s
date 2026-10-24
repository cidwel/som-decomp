.setcpu "65816"
.segment "CODE"
.org $7E44
map_control_0e7e44:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
