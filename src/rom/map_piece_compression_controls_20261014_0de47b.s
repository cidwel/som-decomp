.setcpu "65816"
.segment "CODE"
.org $E47B
map_control_0de47b:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $DB ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
