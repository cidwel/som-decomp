.setcpu "65816"
.segment "CODE"
.org $8675
map_control_0f8675:
    .byte $CF ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A2 ; row-distance/count
