.setcpu "65816"
.segment "CODE"
.org $6AD5
map_control_0d6ad5:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C1 ; same-value copy count/distance
