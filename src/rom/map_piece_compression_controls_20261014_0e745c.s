.setcpu "65816"
.segment "CODE"
.org $745C
map_control_0e745c:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
