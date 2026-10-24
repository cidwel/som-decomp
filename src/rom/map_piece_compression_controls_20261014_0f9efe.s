.setcpu "65816"
.segment "CODE"
.org $9EFE
map_control_0f9efe:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
