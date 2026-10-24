.setcpu "65816"
.segment "CODE"
.org $5FBD
map_control_0d5fbd:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
