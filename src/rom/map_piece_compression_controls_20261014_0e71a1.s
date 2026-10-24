.setcpu "65816"
.segment "CODE"
.org $71A1
map_control_0e71a1:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
