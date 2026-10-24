.setcpu "65816"
.segment "CODE"
.org $A821
map_control_0da821:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
