.setcpu "65816"
.segment "CODE"
.org $C2FC
map_control_0fc2fc:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
