.setcpu "65816"
.segment "CODE"
.org $77B5
map_control_0c77b5:
    .byte $C3 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $43 ; row-distance/count
