.setcpu "65816"
.segment "CODE"
.org $02CB
map_control_0f02cb:
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
