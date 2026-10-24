.setcpu "65816"
.segment "CODE"
.org $8DC4
map_control_0f8dc4:
    .byte $CA ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
