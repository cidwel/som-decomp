.setcpu "65816"
.segment "CODE"
.org $B435
map_control_0db435:
    .byte $DF ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E6 ; previous-row copy count
