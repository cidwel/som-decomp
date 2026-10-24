.setcpu "65816"
.segment "CODE"
.org $752A
map_control_0c752a:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
