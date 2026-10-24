.setcpu "65816"
.segment "CODE"
.org $6F5C
map_control_0d6f5c:
    .byte $D4 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count
