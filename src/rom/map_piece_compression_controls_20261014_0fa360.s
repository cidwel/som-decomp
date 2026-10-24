.setcpu "65816"
.segment "CODE"
.org $A360
map_control_0fa360:
    .byte $DD ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E7 ; previous-row copy count
