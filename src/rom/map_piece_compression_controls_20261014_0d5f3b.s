.setcpu "65816"
.segment "CODE"
.org $5F3B
map_control_0d5f3b:
    .byte $CD ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E3 ; previous-row copy count
