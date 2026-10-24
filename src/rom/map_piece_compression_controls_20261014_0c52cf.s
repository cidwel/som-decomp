.setcpu "65816"
.segment "CODE"
.org $52CF
map_control_0c52cf:
    .byte $E2 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
