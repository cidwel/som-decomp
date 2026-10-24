.setcpu "65816"
.segment "CODE"
.org $44E0
map_control_0f44e0:
    .byte $C1 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
