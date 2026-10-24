.setcpu "65816"
.segment "CODE"
.org $77B7
map_control_0e77b7:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E4 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
