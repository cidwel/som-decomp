.setcpu "65816"
.segment "CODE"
.org $A787
map_control_0fa787:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
