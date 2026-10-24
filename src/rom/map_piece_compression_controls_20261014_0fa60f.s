.setcpu "65816"
.segment "CODE"
.org $A60F
map_control_0fa60f:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C9 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
