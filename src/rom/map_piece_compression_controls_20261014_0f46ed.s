.setcpu "65816"
.segment "CODE"
.org $46ED
map_control_0f46ed:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
