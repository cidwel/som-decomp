.setcpu "65816"
.segment "CODE"
.org $AADC
map_control_0eaadc:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $51 ; row-distance/count
