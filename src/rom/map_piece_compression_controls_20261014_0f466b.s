.setcpu "65816"
.segment "CODE"
.org $466B
map_control_0f466b:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
