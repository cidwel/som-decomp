.setcpu "65816"
.segment "CODE"
.org $6B53
map_control_0f6b53:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
