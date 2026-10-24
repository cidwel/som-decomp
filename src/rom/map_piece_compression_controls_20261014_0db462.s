.setcpu "65816"
.segment "CODE"
.org $B462
map_control_0db462:
    .byte $D5 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
