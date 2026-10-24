.setcpu "65816"
.segment "CODE"
.org $C9AF
map_control_0dc9af:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
