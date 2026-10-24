.setcpu "65816"
.segment "CODE"
.org $EEF2
map_control_0deef2:
    .byte $CF ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count
