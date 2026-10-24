.setcpu "65816"
.segment "CODE"
.org $36DE
map_control_0e36de:
    .byte $E4 ; previous-row copy count
    .byte $DA ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
