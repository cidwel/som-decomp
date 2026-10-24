.setcpu "65816"
.segment "CODE"
.org $5D3A
map_control_0d5d3a:
    .byte $E3 ; previous-row copy count
    .byte $CB ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
