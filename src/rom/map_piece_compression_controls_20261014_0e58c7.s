.setcpu "65816"
.segment "CODE"
.org $58C7
map_control_0e58c7:
    .byte $CD ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
