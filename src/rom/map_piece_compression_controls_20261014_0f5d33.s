.setcpu "65816"
.segment "CODE"
.org $5D33
map_control_0f5d33:
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
